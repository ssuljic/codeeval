class Point
  attr_reader :x, :y

  def initialize(x, y)
    @x = x
    @y = y
  end
end

def distance(point1, point2)
  Math.sqrt((point1.x - point2.x)**2 + (point1.y-point2.y)**2)
end

File.open(ARGV[0]).each_line do |line|
  parsed = line.gsub(', ', ',').gsub('(', '').gsub(')', '').split(' ')
  a = Point.new(parsed[0].split(',')[0].to_i, parsed[0].split(',')[1].to_i)
  b = Point.new(parsed[1].split(',')[0].to_i, parsed[1].split(',')[1].to_i)
  puts distance(a,b).to_i
end