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
    new Point(34, 409),
    new Point(270, 462),
    new Point(322, 410),
    new Point(384, 265),
    new Point(458, 172),
    new Point(550, 70),
    new Point(644, 446),
    new Point(830, 79),
  ]
}