all:
  g++ main.cpp -I. -o hangman
  
clean:
  rm -f hangman
