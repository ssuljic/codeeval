File.open(ARGV[0]).each_line { |line| puts line.strip.split('').permutation.map(&:join).sort.join(',') }
