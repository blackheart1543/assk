max=int(input("Enter hast table size: "))
ht = [-1]*max
ht1 = [-1]*max
print(ht)
keys=[]
def LinearProbe(k):
 pos=k%max
 if(ht[pos]==-1):
 ht[pos]=k
 else:
 while(ht[pos]!=-1):
 pos=(pos+1)%max
 ht[pos]=k
def QuadraƟcProbe(k):
 pos=k%max
 if(ht1[pos]==-1):
 ht1[pos]=k
 else:
 i=1
 while True:
 newpos=(pos+(i*i))%max
 if(ht1[newpos]==-1):
 ht1[newpos]=k
 break
 i=i+1
def insert():
 print("\tPerforming Linear Probing: ")
 print("\nEnter the keys below: ")
 ans=1
 cnt=1
 while(ans==1):
 key=int(input("Enter key: "))
 keys.append(key)
 LinearProbe(key)
 print(ht)
 cnt=cnt+1
 if(cnt>max):
 print("Hash table is full!")
 print(ht)
 break
 ans=int(input("Enter more?(1/0) "))

 print("\tPerforming QuadraƟc Probing on same key set: ")
 print("keys: ", keys)
 for i in keys:
 QuadraƟcProbe(i)
 print(ht1)
def Lsearch(k):
 pos=k%max
 global lcmp
 lcmp=0
 lcmp+=1
 if(ht[pos]==k):
 return pos
 else:
 loc=(pos+1)%max
 for i in range(max-1):
 lcmp+=1
 if(ht[loc]==k):
 return loc
 loc=(loc+1)%max
 return -1
def Qsearch(k):
 pos=k%max
 global qcmp
 qcmp=0
 qcmp+=1
 if(ht1[pos]==k):
 return pos
 else:
 stepcount=1
 for i in range(max-1):
 newpos=(pos+(stepcount*stepcount))%max
 qcmp+=1
 if(ht1[newpos]==k):
 return newpos
 stepcount+=1
 return -1

def menu():
 while True:
 #os.system('clear')
 print("***********Menu************")
 print("1.Insert")
 print("2.Display")
 print("3.Search")
 print("4.Exit")

 n=int(input("Enter your choice: "))
 if(n==1):
 global ht, ht1, keys
 ht=[-1]*max
 ht1=[-1]*max
 keys=[]
 insert()
 elif(n==2):
 print("\nUsing Linear probing: ",ht)
 print("\nUsing QuadraƟc probing: ",ht1)
 elif(n==3):
 print("\nUsing Linear probing: ",ht)
 print("\nUsing QuadraƟc probing: ",ht1)
 k=int(input("\nEnter key to search: "))
 print("\n\tLinear search: ")
 locaƟon=Lsearch(k)
 if(locaƟon==-1):
 print("Element not found")
 else:
 print("Element found at index: ", locaƟon, "with ", lcmp, "number of comparison(s).")
 if(locaƟon!=-1):
 locaƟon=Qsearch(k)
 print("\n\tQuadraƟc search below:")
 print("Element found at index: ", locaƟon, "with", qcmp, "number of comparison(s)")
 elif(n==4):
 print("\n\t\tProgram Ends.")
 break
 else:
 print("\t\tInvalid input!") 
