from PIL import Image
def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return "".join([str(d) for d in digits[::-1]])

test = numberToBase(69, 7)
print(int(str(test), 7))


flag = "0CTF{I_c@n_pl@y_w0nd3rw@ll_n0w}"
letters = "CDEFGAB"

flag = [ord(c) for c in flag]
print(flag)

flag = [numberToBase(c, 7) for c in flag]
print(flag)


flag = [[o for o in c] for c in flag]
print(flag)


flag = [[int(o) for o in c] for c in flag]
print(flag)

flag = [[letters[o - 1] for o in c] for c in flag]
print(flag)


flag = ["".join(c) for c in flag]
print(" ".join(flag))


solution = lambda enc: "".join([chr(int("".join([str((letters.find(c) + 1)%7) for c in ch]), 7)) for ch in enc])
print(solution(flag))



# flag = solution(flag)
# print(flag)

print(flag)
letterImages = {}
for l in letters:
	letterImages[l] = Image.open(f"{l}.png")
print(letterImages)

lw, lh = letterImages["C"].size

challenge = Image.new(mode = "RGB", size = (lw*3, lh*len(flag)))

for y, septal in enumerate(flag):
	for x, c in enumerate(septal):
		challenge.paste(letterImages[c], (x*lw, y*lh))
challenge.save("chal.png")
