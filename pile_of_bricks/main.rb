class Brick
  attr_reader :index, :point1, :point2

  def initialize(index, point1, point2)
    @index = index
    @point1 = point1
    @point2 = point2
  end

  def sides
    ret = []
    ret << [(point1[0] - point2[0]).abs, (point1[1] - point2[1]).abs]
    ret << [(point1[1] - point2[1]).abs, (point1[2] - point2[2]).abs]
    ret << [(point1[2] - point2[2]).abs, (point1[0] - point2[0]).abs]
    ret
  end
end

File.open(ARGV[0]).each_line do |line|
  hole, bricks = line.split('|')
  hole.gsub!(/[\[\]]/, '')
  point1, point2 = hole.split(' ')
  x1, y1 = point1.split(',').map(&:to_i)
  x2, y2 = point2.split(',').map(&:to_i)
  hole_side1 = (x2 - x1).abs
  hole_side2 = (y2 - y1).abs

  bricks.gsub!(/[\[\]\(\)]/, '')
  bricks = bricks.split(';').map do |brick|
    index, point1, point2 = brick.split(' ')
    Brick.new(index.to_i, point1.split(',').map(&:to_i), point2.split(',').map(&:to_i))
  end

  possible = []
  bricks.each do |brick|
    brick.sides.each do |sides|
      if (sides[0] <= hole_side1 && sides[1] <= hole_side2) || (sides[1] <= hole_side1 && sides[0] <= hole_side2)
        possible << brick.index
        break
      end
    end
  end
  puts possible.empty? ? '-' : possible.sort!.join(',')
end