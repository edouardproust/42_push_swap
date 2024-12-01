# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 19:36:03 by eproust           #+#    #+#              #
#    Updated: 2024/12/01 18:38:56 by eproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

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
    if [ "$progress" -eq "$total" ]; then
        printf "\r[%s] %3d / %d" "$bar" "$progress" "$total"
    else
        printf "\r[%s%s] %3d / %d" "$bar" "$empty" "$progress" "$total"
    fi
}

for i in $(seq 1 $total_runs); do
    output+=$(make loop ARGS="$(./generator 500)")
    progress_bar $i $total_runs
done

echo -e "\n$output"
echo -e "\nKO tests: $(echo "$output" | grep -c "KO")"
echo "Tests with 5500+ moves: $(echo "$output" | grep -oP '\d+' | awk '$1 > 5500' | wc -l)"
