#!/usr/bin/python3
if __name__ == "__main__":
    import hidden_4
    # now lets show  sorted 
    for name in sorted(dir(hidden_4)):
        #print it in nice format
        if name[:2] != '__':
            print("{}".format(name))
