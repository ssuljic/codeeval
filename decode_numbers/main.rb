def count_ways(encoded)
  return 0 if encoded.size == 0
  cache = [1, 0, 0]

  (encoded.size - 1).downto(0).each do |i|
    cache[2] = cache[1]
    cache[1] = cache[0]
    cache[0] = 0
    cache[0] += cache[1] if i < encoded.size && encoded[i].to_i >= 1 && encoded[i].to_i <= 9
    cache[0] += cache[2] if encoded[i] == '1' || (encoded[i] == '2' && encoded[i+1].to_i >= 0 && encoded[i+1].to_i <= 6)
  end

  cache[0]
end

File.open(ARGV[0]).each_line do |line|
  num = line.strip
  puts count_ways(num)
end