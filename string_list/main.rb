File.open(ARGV[0]).each_line do |line|
  n = line.split(',').first.to_i
  letters = line.split(',').last.strip.split('').uniq
  puts letters.repeated_permutation(n).map(&:join).sort.join(',')
end
