# Boond Boond Se Sagar Banta Hai (Reverse) (Medium)
    - Move player on an ascii canvas.
    - Paint or unpaint a cell.
    - Save the canvas into a string.
    - Once all the states are done, hash them and check them with a constant.
    - If hash verified, then say you won.


# Text Echoer (PWN) (Easy)
    - Get x, y position from user.
    - Get string from user.
    - Store x, y and the string into a structure. Store the string using strcpy.
    - The strcpy will overflow the buffer.
    - The Return print the string at that x and y position.

# Simplistic Image Format (Reverse) (Hard)
    - The rgb values are store in a single long number
    - 111111111 = 255
    - thus each pixel will be stored as 111111111_111111111_111111111 (Remove the _)
    - So (255, 255, 255) = 134217727 = 0b111111111111111111111111111, (0, 0, 0) = 0 = 0b000000000000000000000000000
    - Use left/right shifts to get the data for each colour.
    - The challenge will give a website.
    - So the page will take an image, convert it to .SIF and return it.
    - No source code will be provided.
    - The users have to figure out the format themselves.
    - The flag will be in a .SIF file and users have to decode it themselves.
    - Simple.
    > SIG
    > 100x100
    > RGB
    > 111111111111111111111111111000000000000000000000000000111111111111111111111111111000000000000000000000000000111111111111111111111111111000000000000000000000000000
    > MD5 Hash of the whole pixel data.
    > TheEnd


# Get this flag and I'll be proud of you. (Reverse) (Medium)
    - The Game is of dropping bombs on vilages and burning them.
    - if the player waits for 30 minutes without doing anything, the game fetches a pastebin url and gets the flag.
    - Will be made in godot, and all the scripts will be obfuscated. The url will be super obfuscated I will make sure of it.

# DRM Challenge (Reverse) (Easy)
    - It will be a simple program that will give you the flag.
    - No tricks or anything, just a simple function that prints the flag.
    - But, hehe
    - before printing the flag, the program will check the hash of the executable itself, and if it mismatches, then wont print the flag.
    - 5 Characters of the flag will be changed in the binary itself (Using hexedit) and then that will given as the challenge.
    - The player has to bruteforce the flag, and check the contents using the md5 algo. Although not specified, we will use an implementation of md5 and add a few characters to it to confuse the player.

#  