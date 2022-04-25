#!/bin/bash

github_user_name="$(git config --list | awk -F\user.name= '$0=$2')"

declare -A user_array=(["Gurvan Le Letty"]=".github/environement/.gurvan.env" ["Clement Fernandes"]=".github/environement/.clement.env"  ["Maxime Carabina"]=".github/environement/.maxime.env")

if [[ ${user_array[$github_user_name]} ]]; then
    printf "\033[0;32m✓\033[0m User found ...\n"
    printf "Processing ...\n"
else
    printf "Unknown user '$github_user_name' ...\n" >&2
    printf "Exiting ...\n" >&2
    exit 1
fi

for name in "${!user_array[@]}"; do
    if [[ $github_user_name =~ $name ]]; then
        printf "Welcome $name\n"
        sleep 1
        gh secret set --env-file ${user_array[$name]}
        git config --list
    fi
done