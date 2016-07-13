def valid?(card)
  sum = 0
  card.split('').reverse.each_with_index do |digit, index|
    if index % 2 == 0
      sum += digit.to_i
      next
    end
    num = digit.to_i
    num *= 2
    num = num.to_s.split('').map(&:to_i).inject(:+) if num > 9
    sum += num
  end
  sum % 10 == 0
end

File.open(ARGV[0]).each_line do |line|
  card = line.gsub(' ', '').strip
  puts valid?(card) ? 1 : 0
end