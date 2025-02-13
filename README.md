# pipex

Welcome, human.

'git push' shortcut:
git config --global alias.upload '!git add . && git commit -m "v0.1" && git push'

'valgrind' command:

 valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes -s ./pipex infile "grep hello" "wc -l" outfile