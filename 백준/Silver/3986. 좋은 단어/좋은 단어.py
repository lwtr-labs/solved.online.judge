n = int(input())

count = 0

for i in range(n):
    st = []    

    x = str(input())

    for j in range(len(x)):
        if st == []:
            st.append(x[j])
        else:
            if x[j] == st[len(st)-1]:
                st.pop()
            else:
                st.append(x[j])
    if len(st) == 0:
        count += 1
print(count)