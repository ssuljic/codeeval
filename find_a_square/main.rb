class Point
  attr_accessor :x, :y

  def initialize(x, y)
    @x = x
    @y = y
  end

  def self.parse_input_line(line)
    points = line.split(', ')
    points.map do |p|
      x_c, y_c = p.scan(/\d/)
      Point.new(x_c.to_i, y_c.to_i)
    end
  end

  def squared_distance_to(point)
    (x - point.x) ** 2 + (y - point.y) ** 2
  end
end

class Shape
  attr_accessor :points

  def initialize(points)
    @points = points
  end

  def square?
    return false if points.size != 4
    d1 = points[0].squared_distance_to(points[1])
    d2 = points[0].squared_distance_to(points[2])
    d3 = points[0].squared_distance_to(points[3])

    return false if d1 == 0 || d2 == 0 || d3 == 0

    if d1 == d2 && 2*d1 == d3
      d13 = points[1].squared_distance_to(points[3])
      d23 = points[2].squared_distance_to(points[3])
      return d13 == d23 && d13 == d1
    end

    if d2 == d3 && 2*d2 == d1
      d21 = points[2].squared_distance_to(points[1])
      d31 = points[3].squared_distance_to(points[1])
      return d21 == d31 && d21 == d2
    end

    if d1 == d3 && 2*d1 == d2
      d12 = points[1].squared_distance_to(points[2])
      d32 = points[3].squared_distance_to(points[2])
      return d12 == d32 && d12 == d1
    end

    false
  end
end

File.open(ARGV[0]).each_line do |line|
  points = Point.parse_input_line(line)
  shape = Shape.new(points)
  puts line
  puts shape.square?
end