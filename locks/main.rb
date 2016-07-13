def make_iteration(doors)
  doors.each_with_index do |door, i|
    doors[i] = true if (i+1) % 2 == 0
  end

  doors.each_with_index do |door, i|
    doors[i] = !door if (i+1) % 3 == 0
  end
end

def count_unlocked(n, iterations)
  doors = Array.new(n) { |i| false }
  (iterations - 1).times do
    make_iteration(doors)
  end
  doors[doors.size - 1] = !doors[doors.size - 1]
  doors.count { |door| !door }
end

File.open(ARGV[0]).each_line do |line|
  doors, iterations = line.split(' ').map(&:to_i)
  puts count_unlocked(doors, iterations)
end