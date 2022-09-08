user_msg = input('Enter your message: ')
words = user_msg.split(' ')

emojis_map = {
    ':)': '😊',
    ':(': '😞',
    ':o': '😮',
    '0:)': '😇'
}
output_msg = ''
for word in words:
    # === Way 3 ====
    output_msg += emojis_map.get(word, word) + ' '
    # === Way 1 ====
    # if word in emojis_map:
    #     output_msg += emojis_map[word]
    # else:
    #     output_msg += word
    # === Way 2 ====
    # output_msg += emojis_map[word] if word in emojis_map else word
    # output_msg += ' '

print(output_msg)
