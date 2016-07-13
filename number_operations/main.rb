class ExpressionEval
  def initialize(numbers, operations)
    @numbers = numbers
    @operations = operations
  end

  def possible?(number)
    @numbers.permutation(5).each do |p|
      @operations.repeated_permutation(4).each do |rp|
        if eval_expression(p, rp) == number
          return true
        end
      end
    end
    false
  end

  private

  def eval_expression(nums, ops)
    tmp = nums[0]
    (0..3).each do |i|
      tmp = tmp.send(ops[i], nums[i+1])
    end
    tmp
  end
end

File.open(ARGV[0]).each_line do |line|
  numbers = line.split(' ').map(&:to_i)
  operations = [:+, :-, :*]
  ee = ExpressionEval.new(numbers, operations)
  puts ee.possible?(42) ? 'YES' : 'NO'
end