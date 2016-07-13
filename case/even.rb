File.open(ARGV[0]).each_line { |line| puts line.to_i.even? ? 1 : 0 }
