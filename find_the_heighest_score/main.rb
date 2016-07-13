File.open(ARGV[0]).each_line do |line|
  rows = line.split('|')
  nums = rows.map { |r| r.split(' ').map(&:to_i) }
  puts nums.transpose.map(&:max).join(' ')
end