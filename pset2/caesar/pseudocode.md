[X]Get the Key point from the user using command arguements
    [X]Only One arguement should be provided 
    [X]Iterate arguement to check if its digits
    [X]Coverting the arguement into an Integer (string to int)

[X]Prompy for plain text from the user
    [X]Useing fgets to get the user input

[X]Encipher that plain text using the key given
    [X]Iterate over each character of the plaintext
        [X]if alphabetic, shift plaintext chracter by key, preserving the case
        [X]if it's not alphabetic, like (space, or speical charaters , or -) leave as-is
            *isalpha() - return True if its a alphabetic else False
            *isupper() - return True if its upper case else False
            *islower() - reutnr True if its lower case else False

            //ASCII Alphabetic Valuses
                * A - Z : 65 - 90
                * a - z : 97 - 122
            
        //When is reaches Z or z we want it to go back to A - a
        [X]Convert ASCII to aplhabetic index
        [X]Shift aplhabetical index using formula
        [X]Convert result back to ASCII
        {Formula: ci = (pi + k ) % 26}
[X]Print out the ciphered text