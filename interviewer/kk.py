import json

'''
jsondump 实现类似json里面 json.dumps功能
'''
def jsondump(dic):
	if isinstance(dic, dict):
		arr = []
		for key, value in dic.items():
			line = '"'+ key + '"' + ":" + str(value)
			arr.append(line)
		ret = "{" +  ','.join(arr) + "}"
		return ret
	return ""

dic = {"a":2, "b":1}
print(jsondump(dic))

'''
func 用于实现统计字符串中字母的出现次数。
'''
def func(sstr):
	if isinstance(sstr, str):
		dic = {}
		for c in sstr:
			if c.isalpha():
				c = c.lower()
				if c not in dic:
					dic[c] = 1
				else:
					dic[c]+=1
		print(f"dic:{dic}")
		return json.dumps({"a":2, "c":3})

func("aAb123")

