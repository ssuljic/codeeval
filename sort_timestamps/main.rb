require 'time'

class Timestamp
  attr_accessor :timestamp, :input

  def initialize(t)
    @input = t
    @timestamp = Time.parse(t)
  end
end

File.open(ARGV[0]).each_line do |line|
  timestamps = line.split(' ')
  timestamps = timestamps.map { |t| Timestamp.new(t) }
  puts timestamps.sort_by { |t| t.timestamp }.reverse.map(&:input).join(' ')
end