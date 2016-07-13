DISTANCE_TO_WALL = 6

File.open(ARGV[0]).each_line do |line|
  elems = line.split(' ').map(&:to_i)
  l = elems.shift
  d = elems.shift
  n = elems.shift
  puts "L #{l} D #{d}"
  elems.sort!
  elems.unshift(DISTANCE_TO_WALL - 1)
  elems.push(l - DISTANCE_TO_WALL + 1)
  elems = elems.uniq
  puts "#{elems}"
  count = 0

  elems.each_with_index do |el, index|
    next if index == elems.count - 1
    puts "BETWEEN #{el} AND #{elems[index+1]} " + ((elems[index+1] - el - 1).to_f / d).to_s
    count += (elems[index+1] - el) / d
  end

  puts "!!!!!!!!!!!!!! #{count}\n\n"
end

# 33 5
# 6 11 16 21 26