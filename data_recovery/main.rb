require 'time'

class Pair
  attr_accessor :value, :order

  def initialize(value, order)
    @value = value
    @order = order
  end
end

File.open(ARGV[0]).each_line do |line|
  input = line.split(';').map { |part| part.split(' ') }
  pairs = []
  orders = Hash.new { |hash, key| hash[key] = 0 }
  input[0].each_with_index do |word, i|
    order = input[1][i].to_i
    pairs << Pair.new(word, order)
    orders[order] += 1
  end
  (1..pairs.size).each do |order|
    pairs.last.order = order if orders[order] == 0
  end
  puts pairs.sort_by { |p| p.order }.map(&:value).join(' ')
end