File.open(ARGV[0]).each_line do |line|
    x, y, range = line.split(' ').map(&:to_i)
    (1..range).each do |i|
        print 'F' if i % x == 0
        print 'B' if i % y == 0
        print i if i % x != 0 && i % y != 0
        print ' '
    end
    print "\n"
end