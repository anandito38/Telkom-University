#definisi CFG
print('Inputan: if <var> <op> <var> { <var> = <angka> }else{ <var> = <angka> }')
print('<var> := a, b')
print('<op> := ==, >=, <=, >, <')
print('<angka> := 1, 2\n')

#jenis token
#alphabet
var = ['a', 'b']
#bilangan bulat
n = ['1', '2']
#perbandingan
op = ['==', '>=', '<=', '>', '<']
#simbol lainnya
statement = ['if', '{', '}else{', '}', '=']

def get_token(teks, j):
    k = len(teks)
    kata = ""

    # abaikan spasi dan pindah baris
    while teks[j] == ' ' or teks[j] == '\r' or teks[j] == '\n':
        j += 1

    # ambil 1 kata/token
    while j < k and teks[j] != ' ' and teks[j] != '\r' and teks[j] != '\n':
        if teks[j] == '>':
            if kata != '':
                return kata
            else:
                j += 1
                if teks[j] == '=':
                    j += 1
                    return ">="
                else:
                    return ">"
        elif teks[j] == '<':
            if kata != '':
                return kata
            else:
                j += 1
                if teks[j] == '=':
                    j += 1
                    return "<="
                else:
                    return "<"
        elif teks[j] == '=':
            if kata != '':
                return kata
            else:
                j += 1
                return "="
        kata += teks[j]
        j += 1

    return kata

# count token
def tokens(sentence):
    i = 0
    chrlength = len(sentence)
    hasil = ""

    while i < chrlength:
        token = get_token(sentence, i)

        if token not in var and token not in n and token not in op and token not in statement:
            return "Invalid input token"

        i = i + len(token)
        while i < chrlength and (sentence[i] == ' ' or sentence[i] == '\r' or sentence[i] == '\n'):
            i = i + 1

    return sentence

# input user
print('Masukkan kalimat: ')
sentence = input()
loop = tokens(sentence)
list_output = loop.split()
for i in list_output:
    if i == "}else{":
        print("}")
        print("else")
        print("{")
        continue
    print(i)

