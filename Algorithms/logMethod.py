#Figure out how many b's create the target input.. 
#log base(target) = x?
def logMethod(target, base):	
#Method to Binary Search between the closet number we got, and one above it..
#This will take in the highest value you've reached before remainders, target, and base..
	def bs_rem(target_,base_,prec_):
		start = 0
		end = 1
		mid = 0.5
		#Precision check, loop can only go (prec you want)^2  before force escape.. otherwise it should be found when inside loop..
		#Set this higher or greater depending on the application.. Another method would be to simply round..
		#You could round that mx and target to (number_you_want, decimal_precision)..
		#Whichever method you use, eventually there has to be a force escape as some logs have infinite decimals..
		count = prec_**2
		while(count>0):
			mx = (base_**mid) #easy access
			#Return if you found the match..
			if(mx==target_):
				return mid

			if(mx>target_):
				end = mid
			else:
				start = mid

			mid = (start+end)/2.0
			count-=1
		return mid
#Count how many times you can divide target/base evenly before the remainder occurs 
	division_count = 0
	x = float(target)
	while(x>=base):
		x/=base
		division_count+=1
#If we divided up until x==1, this is great, this is what we return.. otherwise we must bs between that n and n+1..
#bs_rem will take in the target, base, and the precision.. method binary searches between 0 and 1 to find what will work..
	return (division_count if x==1 else division_count+bs_rem(x,base,8)) 
  
  
 #take in the target, then base..
print(math.log(16,2))
print(logMethod(16,2))

print(math.log(25,2))
print(logMethod(25,2))

print(math.log(81,3))
print(logMethod(81,3))

print(math.log(111,3))
print(logMethod(111,3))

print(math.log(125,5))
print(logMethod(125,5))

print(math.log(2731693,5))
print(logMethod(2731693,5))

print(math.log(285311670611,11))
print(logMethod(285311670611,11))

print(math.log(314224634523624623463463463462346234634634646323642346346124314224634523624623463463463462346234634634646323642346346124314224634523624623463463463462346234634634646323642346346124314224634523624623463463463462346234634634646323642346346124,11))
print(logMethod(314224634523624623463463463462346234634634646323642346346124314224634523624623463463463462346234634634646323642346346124314224634523624623463463463462346234634634646323642346346124314224634523624623463463463462346234634634646323642346346124,11))

  
