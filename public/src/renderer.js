export default class Renderer {
  constructor(points) {
    this.c = document.querySelector('canvas')
    this.ctx = this.c.getContext('2d')
    this.points = points
    this.width = this.c.width
    this.height = this.c.height

    this.drawPoints()

    // this.c.style.width = '1000px'
    // this.c.style.height = '1000px'
  }

  clear() {
    this.ctx.clearRect(0, 0, this.width, this.height)
    this.drawPoints()
  }

  selectRect(a, b) {
    this.clear()
    const x1 = this.drawLineToTheLeft(a)
    const x2 = this.drawLineToTheLeft(b)
    this.ctx.fillStyle = "#70C2BB"
    this.ctx.fillRect(x1, 0, x2 - x1, 500)
    this.drawPoints()
  }

  drawRect(x1, x2) {
    this.clear()
    this.ctx.moveTo(x1, 0)
    this.ctx.lineTo(x1, this.height)
    this.ctx.stroke()
    this.ctx.moveTo(x2, 0)
    this.ctx.lineTo(x2, this.height)
    this.ctx.stroke()
    this.ctx.fillStyle = "#70C2BB"
    this.ctx.fillRect(x1, 0, x2 - x1, 500)
    this.drawPoints()
  }

  drawPoints() {
    this.points.forEach(p => this.drawPoint(p));
    for (let i=0; i < this.points.length; i++) {
      this.drawPoint(i)
    }
  }

  drawPoint(point) {
    this.ctx.fillStyle = "#555555"
    this.ctx.beginPath()
    this.ctx.arc(point.x, point.y, 5, 0, 2 * Math.PI);
    this.ctx.fill()
  }

  drawLine(pair) {
    this.ctx.strokeStyle = "#a55555"
    this.ctx.moveTo(pair[0].x, pair[0].y)
    this.ctx.lineTo(pair[1].x, pair[1].y)
    this.ctx.stroke()
    this.drawPoint(pair[0])
    this.drawPoint(pair[1])
  }

  drawLineToTheLeft(index) {
    let x
    if (index >= this.points.length) x = this.width
    else if (index <= 0) x = 0
    else x = this.points[index].xAvg(this.points[index -1])
    this.ctx.strokeStyle = "#000000"
    this.ctx.moveTo(x, 0)
    this.ctx.lineTo(x, 500)
    this.ctx.stroke()
    return x
  }
}
