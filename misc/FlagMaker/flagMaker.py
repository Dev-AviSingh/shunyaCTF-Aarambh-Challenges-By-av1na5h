substitutions = {
	"a":"@",
	"e":"3",
	"t":"7",
	"i":"1",
	"A":"4",
	"s":"5",
	"o":"0",
	"O":"0",
	"S":"5",
	" ":"_"
}


flag = "I can play wonderwall now"
format_ = "0CTF"


n = ""
for f in flag:
	if f in substitutions:
		n+= substitutions[f]
	else:
		n+= f

print(f"{format_}{{{n}}}")