
def dbg(xaddr):
    import gdb
    import string
    gdb.execute('file ./otp')
    valid = ['a','b','c','d','e','f']
    for i in range(0,10):
        valid.append("{}".format(i))

    #gdb.execute("b main")
    #gdb.execute("b *{}".format(baddr))
    desired = "mngjlepdcbcmjmmjipmmegfkjbicaemoemkkpjgnhgomlknmoepmfbcoffikhplmadmganmlojndmfahbhaancamdhfdkiancdjf"
    found_key = ""

    while len(found_key) < 100:
        found = False
        for c in valid:
            attempt = found_key
            while len(attempt) < 100:
                attempt += c

            gdb.execute("r {}".format(attempt))
            gdb.execute("c")
            scrambled = gdb.execute("x/gs {}".format(xaddr), to_string=True)
            print(scrambled)
            if(len(scrambled.split('"'))>1):
                #if(len(scrambled.split('"')[1]) > 1)
                if(scrambled.split('"')[1][len(found_key)] == desired[len(found_key)]):
                    found_key += c
                    print("FOUND_KEY: {}".format(found_key))
                    with open("key.txt", 'w') as f:
                        f.write("last attempt: {}\n".format(attempt))
                        f.write("key: {}\n".format(found_key))
                    #print(c)
                    found = True
            else:
                print("Split failed")
        if not found:
            print("Failed at: {}".format(attempt))
            break


