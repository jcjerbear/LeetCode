from collections import OrderedDict


class LRUCache:

    def __init__(self, capacity: 'int'):
        self.dic = OrderedDict()
        self.remain = capacity

    def get(self, key: 'int') -> 'int':
        # if the key does not exist within the dictionary, then we return -1
        if key not in self.dic:
            return -1
        # otherwise, we pop the key and then put it back to the dictionary as the newest entry and then return the get key's value
        v = self.dic.pop(key)
        self.dic[key] = v
        return v

    def put(self, key: 'int', value: 'int') -> 'None':
        # if the key exists within the dictionary already then we pop the key
        if key in self.dic:
            self.dic.pop(key)
        # if the key does not exist in the dictionary then we do the following
        else:
            # if the remaining slots within the dictionary is still greater than 0 then we minus remain by 1
            if self.remain > 0:
                self.remain -= 1
            # if the remaining slots within the dictionary is 0 meaning that the dictionary is full already then we pop a pair out in a queue fashion
            else:
                self.dic.popitem(last=False)
        # and then eventually we put the pair into the dictionary
        self.dic[key] = value


if __name__ == '__main__':
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.get(1)       # returns 1
    cache.put(3, 3)    # evicts key 2
    cache.get(2)       # returns -1 (not found)
    cache.put(4, 4)    # evicts key 1
    cache.get(1)       # returns -1 (not found)
    cache.get(3)       # returns 3
    cache.get(4)       # returns 4
