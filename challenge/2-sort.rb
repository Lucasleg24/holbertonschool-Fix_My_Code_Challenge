###
#
#  Sort integer arguments (descending)
#
###

result = []
ARGV.each do |arg|
    # skip if not integer
    next if arg !~ /^-?[0-9]+$/

    # convert to integer
    i_arg = arg.to_i

    # ajouter l'entier à la liste
    result << i_arg
end

# trier la liste en ordre décroissant
result.sort!

# afficher le résultat
puts result
