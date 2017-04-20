verti,edges = map(int,input().split(" "))
lis=[];
for i in range(verti):
	l = [];
	for j in range(verti):
		l.append(0);
	lis.append(l);
for i in range(edges):
	v1,v2,w = map(int,input().split(" "))
	lis[v1-1][v2-1]=w;
	lis[v2-1][v1-1]=w;
print(verti);
for i in lis:
	for j in i:
		print(j,end=" ");
	print();
