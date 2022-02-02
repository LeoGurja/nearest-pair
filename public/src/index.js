import Point from './point.js'
import divideAndConquer from './divideAndConquer.js'
import Renderer from './renderer.js'

const points = initPoints()
const renderer = new Renderer(points)

const result = await divideAndConquer(points, 0, points.length, renderer)
renderer.clear()
renderer.drawPoints()
renderer.drawLine(result)

function initPoints() {
  return [
    new Point(34, 103),
    new Point(270, 320),
    new Point(331, 211),
    new Point(413, 196),
    new Point(505, 91),
    new Point(636, 228),
    new Point(709, 105),
    new Point(830, 337)
  ]
}