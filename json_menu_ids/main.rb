require 'json'

File.open(ARGV[0]).each_line do |line|
  next if line.strip.empty?
  hash = JSON.parse(line)
  puts hash['menu']['items'].map { |item| item.nil? || item['label'].nil? ? nil : item['id'].to_i }.compact.inject(:+).to_i
end