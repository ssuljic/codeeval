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

PARENTHESES = {
  '}' => '{',
  ')' => '(',
  ']' => '['
}

def properly_closed?(string)
  closed = ['}', ')', ']']

  stack = Stack.new
  string.split('').each do |char|
    if PARENTHESES.values.include?(char)
      stack.push(char)
    else
      return 'False' if stack.pop != PARENTHESES[char]
    end
  end
  'True'
end

File.open(ARGV[0]).each_line do |line|
  puts properly_closed?(line)
end