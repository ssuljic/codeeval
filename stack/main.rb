class Stack
  attr_reader :count

  def initialize
    @elements = []
    @count = 0
  end

  def push(number)
    @count += 1
    @elements << number
  end

  def pop
    @count -= 1
    @elements.pop
  end

  def empty?
    @count == 0
  end
end

File.open(ARGV[0]).each_line do |line|
  stack = Stack.new
  line.split(' ').each do |el|
    if el.to_i.to_s == el
      el = el.to_i
      next if el > stack.count
      to_print = nil
      el.times do |e|
        to_print = stack.pop
      end
      puts to_print
    else
      stack.push(el)
    end
  end
end