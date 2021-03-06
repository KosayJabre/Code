# @bootstrap over recursive function
# replace 'return' with 'yield'
# for when sys method does not work
from types import GeneratorType
def bootstrap(f, stack=[]):
	def wrappedfunc(*args, **kwargs):
		if stack:
			return f(*args, **kwargs)
		else:
			to = f(*args, **kwargs)
			while True:
				if type(to) is GeneratorType:
					stack.append(to)
					to = next(to)
				else:
					stack.pop()
					if not stack:
						break
					to = stack[-1].send(to)
			return to
	return wrappedfunc
	
# EXAMPLE recursive fibonacci
@bootstrap
def f(n):
	if (n < 2):
		yield n
	yield (yield f(n-1)) + (yield f(n-2))
