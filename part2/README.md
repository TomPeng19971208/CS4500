This is custom Hashmap that is written in CwC. It is implemented by using an array of a linked list. It stores the data in key-value pairs and retrieve it in constant time. To access a value one must know its associated key.It is known as Hashmap because it uses a technique called hashing.In hashing, hash functions are used to link key and value in hashmap.
Objects are stored by calling put(key, value) of hashmap and retrieve it by calling get(key).When we call put method, hashcode() of key object is called so that hash function can find bucket location to store value object, which is actually an index of internal array, known as the table.It internally stores mapping in the form of Hashnode object which containsboth key and value object.When you want to retrieve an object, you can call get() method and again pass the key object.This time the key object generate the same hashcode and it ends up at the same bucket location.When you call put() method to store the data and the key object generate the same hash code, collision occurs in this case. The data will be append at the end of the linked list.
Since the internal array of Hashmap is of fixed size. If you keep adding data to hashmap, at some point of time internal array will be filled up. The size of array will be doubled(default capacity is 16, so it will be 32 after resized).Also all the elements in the hashmap will be rearranged based on new hashing index.