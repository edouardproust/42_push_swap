# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 19:36:03 by eproust           #+#    #+#              #
#    Updated: 2024/12/01 07:00:24 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Vérifier que l'argument est fourni
if [ -z "$1" ]; then
    echo "Usage: $0 <number_of_runs>"
    exit 1
fi

total_runs=$1
output=""

progress_bar() {
    local progress=$1
    local total=$2
    local bar_length=50
    local filled_length=$((progress * bar_length / total))
    local empty_length=$((bar_length - filled_length))
    local bar=$(printf "%-${filled_length}s" "#" | sed 's/ /#/g')
    local empty=$(printf "%-${empty_length}s" " " | sed 's/ / /g')
    printf "\r[%s%s] %3d / %d done" "$bar" "$empty" "$progress" "$total"
}

for i in $(seq 1 $total_runs); do
    output+=$(make test ARGS="$(./generator 500)")
    progress_bar $i $total_runs
done

echo -e "\nKO: $(echo "$output" | grep -c "KO")"
echo ">5500: $(echo "$output" | grep -oP '\d+' | awk '$1 > 5500' | wc -l)"

