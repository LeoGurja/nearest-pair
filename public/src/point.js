export default class Point {
  constructor(x, y) {
    this.x = x
    this.y = y
  }

  xAvg(point) {
    return (this.x + point.x) / 2
  }
}