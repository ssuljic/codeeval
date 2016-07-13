class Point
  attr_accessor :x, :y

  def initialize(x, y)
    @x = x
    @y = y
  end

  def distance_to(point)
    Math.sqrt((x - point.x) ** 2 + (y - point.y) ** 2)
  end
end

File.open(ARGV[0]).each_line do |line|
  parts = line.split(';')
  center_coordinates = parts[0][/\((.*?)\)/m, 1].split(',').map(&:to_f)
  point_coordinates = parts[2][/\((.*?)\)/m, 1].split(',').map(&:to_f)
  radius = parts[1].split(':')[1].to_f

  center = Point.new(center_coordinates[0], center_coordinates[1])
  point = Point.new(point_coordinates[0], point_coordinates[1])
  puts center.distance_to(point) < radius
end