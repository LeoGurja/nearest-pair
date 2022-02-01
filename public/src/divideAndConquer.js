import timeout from './timeout.js'

function distance(a,b) {
  return Math.sqrt((a.x - b.x)**2 + (a.y - b.y)**2)
}

async function nearestPair(points, begin, end, renderer) {
  const result = []
  let minimumDistance = Infinity
  let currentDistance

  if (end - begin <= 1) throw new Error("impossível")

  for (let i=begin; i < end - 1; i++) {
    for (let j= i + 1; j < end; j++) {
      currentDistance = distance(points[i], points[j])
      renderer.drawLine([points[i], points[j]])
      await timeout()
      if (currentDistance < minimumDistance) {
        minimumDistance = currentDistance
        result[0] = points[i]
        result[1] = points[j]
      }
    }
  }
  return result
}

export default async function divideAndConquer(points, begin, end, renderer) {
  await timeout()
  const size = end - begin

  if (size <= 1) return null
  if (size <= 3) return nearestPair(points, begin, end, renderer)

  const divisionIndex = Math.floor((begin + end) / 2)
  renderer.drawLineToTheLeft(divisionIndex)
  await timeout()

  renderer.selectRect(begin, divisionIndex)
  const leftPair = await divideAndConquer(points, begin, divisionIndex, renderer)
  renderer.selectRect(begin, end)
  renderer.drawLine(leftPair)
  renderer.drawLineToTheLeft(divisionIndex)
  await timeout()
  renderer.selectRect(divisionIndex, end)
  const rightPair = await divideAndConquer(points, divisionIndex, end, renderer)
  renderer.selectRect(begin, end)
  renderer.drawLine(leftPair)
  renderer.drawLine(rightPair)
  renderer.drawLineToTheLeft(divisionIndex)
  await timeout()

  const pair =
    distance(leftPair[0], leftPair[1]) < distance(rightPair[0], rightPair[1]) ?
    leftPair :
    rightPair
  renderer.selectRect(begin, end)
  renderer.drawLine(pair)
  renderer.drawLineToTheLeft(divisionIndex)
  await timeout()

  const delta = distance(pair[0], pair[1])
  const lowerBound = points[divisionIndex].xAvg(points[divisionIndex + 1]) - delta
  const upperBound = points[divisionIndex].xAvg(points[divisionIndex + 1]) + delta
  let lowerIndex, upperIndex

  for (lowerIndex=divisionIndex; lowerIndex > begin && points[lowerIndex].x > lowerBound; lowerIndex--) {}
  for (upperIndex=divisionIndex; upperIndex < end - 1 && points[upperIndex].x < upperBound; upperIndex++) {}

  renderer.drawRect(points[lowerIndex + 1].x, points[upperIndex - 1].x)
  const middlePair = await divideAndConquer(points, lowerIndex + 1, upperIndex, renderer)
  renderer.selectRect(begin, end)
  middlePair && renderer.drawLine(middlePair)
  renderer.drawLine(pair)
  await timeout()
  return (middlePair && distance(middlePair[0], middlePair[1]) < delta) ? middlePair : pair
}