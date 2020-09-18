[X] Get the key from user through command arguement
[X] Valid the key given
    [X]Iterate over the key
        [X]Check if the given key is all alphabets
        [X]Check if its 26 characters
        [X]Check if there are no repeats in key alphabets (case-insensitive)
[X]Prompt User for a plaintext
[X]Encipher the plaintext with the key
    [X]Map each alphabetic A-Z && a-z with the key given case sensitive
    [X]Preserve case.
    [X]Iterate over plaintext
        [X]If non-alphabetic charater (keys its as it is)
        [X]Replace the aplabets with the keys given
[X]Print the ciphertext