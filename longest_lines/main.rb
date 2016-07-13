capacity = nil
lines = []

File.open(ARGV[0]).each_line do |line|
  if capacity.nil?
    capacity = line.to_i
    next
  end

  lines << line
end

lines.sort_by! { |l| -l.length }
lines.first(capacity).each { |line| puts line }