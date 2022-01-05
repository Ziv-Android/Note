from Cryptodome.Cipher import AES
from Cryptodome.Util.Padding import pad, unpad  # 填充方式
from binascii import b2a_hex, a2b_hex
import base64


class ECBandCBC_AES_jiami_AS_jiemi:
    """ECB和CBC模式hex和base64加解密"""

    def add_to_16(self, text):
        """长度补全，必须要使用该方法,密钥和加密的文本内容都必须是固定的16位"""
        if len(text.encode('utf-8')) % 16:  # %求模运算，相当于mod，也就是计算除法的余数，比如5%2就得到1，不是16的倍数
            # print(len(text.encode('utf-8')))
            add = 16 - (len(text.encode('utf-8')) % 16)
            # print(add)
        else:
            # 求模运算等于0的时候
            add = 0
        text = text + ('\0' * add)  # 位数必须要补全
        # return text
        return text.encode('utf-8')

    def ecb_hex_jiami(self, text, keys):
        """EXB HEX加密函数"""
        key = self.add_to_16(keys)
        # key = 'qdwphltib5kyfd3n'.encode('utf-8')  #进行utf-8编码，转为bytes
        mode = AES.MODE_ECB
        text = self.add_to_16(text)
        cryptos = AES.new(key, mode)
        cipher_text = cryptos.encrypt(text)  # 加密，text必须为字节bytes
        print(bytes.decode(b2a_hex(cipher_text)))  # 转换为python的字符串
        return bytes.decode(b2a_hex(cipher_text))  # HEX 16进制输出

    def ecb_hex_jiemi(self, text, keys):
        """ECB HEX解密函数"""
        key = self.add_to_16(keys)
        # key = 'qdwphltib5kyfd3n'.encode('utf-8') #进行utf-8编码，转为bytes
        text = self.add_to_16(text)
        mode = AES.MODE_ECB  # 定义ECB模式
        cryptor = AES.new(key, mode)  # 创建实例
        try:
            plain_text = cryptor.decrypt(a2b_hex(text))  # 解密
            print(bytes.decode(plain_text).rstrip('\0'))
            return bytes.decode(plain_text).rstrip('\0')  # 转换为python的字符串
        except Exception as e:
            return '请检查解密数据或者密钥是否正确！'

    def ecb_base64_jiami(self, text, keys):
        """ECB base64加密函数"""
        key = self.add_to_16(keys)
        mode = AES.MODE_ECB
        cryptos = AES.new(key, mode)
        text = self.add_to_16(text)
        t = cryptos.encrypt(text)  # 加密明文，text必须为字节bytes
        t = base64.encodebytes(t)  # 将返回的字节数据进行base64编码
        t = t.decode('utf-8')  # 将字节型数据转换成python中的字符串类型
        try:
            t = t.split()[0] + t.split()[1]  # 去除换行符
            print(t)
            return t
        except Exception as e:
            return t

    def ecb_base64_jiemi(self, text, keys):
        """ECB base64解密函数"""
        key = self.add_to_16(keys)
        # key = 'qdwphltib5kyfd3n'.encode('utf-8')
        text = base64.b64decode(text)  # 转换为base64格式，为bytes
        mode = AES.MODE_ECB
        cryptor = AES.new(key, mode)
        try:
            plain_text = cryptor.decrypt(text)  # 解密
            print(bytes.decode(plain_text).rstrip('\r'))
            return bytes.decode(plain_text).rstrip('\r')
        except Exception as e:
            return '请检查解密数据或者密钥是否正确！'

    def cbc_hex_jiami(self, text, keys, pyls):
        """CBC加密：HEX加密函数"""
        key = self.add_to_16(keys)
        iv = self.add_to_16(pyls)  # 定义偏移量
        mode = AES.MODE_CBC  # 设置CBC模式
        text = self.add_to_16(text)
        cryptos = AES.new(key, mode, iv)  # 创建实例
        cipher_text = cryptos.encrypt(text)  # 加密，text必须为字节bytes
        print(bytes.decode(b2a_hex(cipher_text)))
        return bytes.decode(b2a_hex(cipher_text))  # HEX 16进制输出

    def cbc_hex_jiemi(self, text, keys, plys):
        """CBC解密：HEX解密函数"""
        key = self.add_to_16(keys)
        iv = self.add_to_16(plys)
        text = self.add_to_16(text)
        mode = AES.MODE_CBC
        cryptor = AES.new(key, mode, iv)  # 创建实例
        try:
            plain_text = cryptor.decrypt(a2b_hex(text))  # 解密
            print(bytes.decode(plain_text).rstrip('\0'))
            return bytes.decode(plain_text).rstrip('\0')  # 转换为python的字符串
        except Exception as e:
            return '请检查解密数据或者密钥是否正确！'

    def cbc_base64_jiami(self, text, keys, plys):
        """CBC base64加密函数"""
        key = self.add_to_16(keys)
        # key = 'qdwphltib5kyfd3n'.encode('utf-8')
        iv = self.add_to_16(plys)
        mode = AES.MODE_CBC
        cryptos = AES.new(key, mode, iv)
        text = self.add_to_16(text)
        t = cryptos.encrypt(text)  # 加密明文，text必须为字节bytes
        t = base64.encodebytes(t)  # 将返回的字节数据进行base64编码
        t = t.decode('utf-8')  # 将字节型数据转换成python中的字符串类型
        try:
            t = t.split()[0] + t.split()[1]  # 去除换行符
            print(t)
            return t
        except Exception as e:
            return t

    def cbc_base64_jiemi(self, text, keys, plys):
        """CBC base64解密函数"""
        key = self.add_to_16(keys)
        iv = self.add_to_16(plys)
        # key = 'qdwphltib5kyfd3n'.encode('utf-8')
        text = base64.b64decode(text)  # 转换为base64格式，为bytes
        mode = AES.MODE_CBC
        cryptor = AES.new(key, mode, iv)
        try:
            plain_text = cryptor.decrypt(text)  # 解密
            print(bytes.decode(plain_text).rstrip('\r'))
            return bytes.decode(plain_text).rstrip('\r')
        except Exception as e:
            return '请检查解密数据或者密钥是否正确！'

    def ctr_base64_jiami(self, text, keys, nonces):
        """CTR base64加密函数"""
        key = self.add_to_16(keys)
        mode = AES.MODE_CTR
        nonces = nonces.encode('utf-8')  # 转换为bytes数据类型
        # text = self.add_to_16(text) # 不指定填充方式，默认为zeropadding填充
        pad_pkcs7 = pad(text.encode(), AES.block_size, style='pkcs7')  # 指定pkcs7填充，和pkcs5输出结果一样
        cryptos = AES.new(key, mode, nonce=nonces)
        t = cryptos.encrypt(pad_pkcs7)  # 加密明文，text必须为字节bytes
        t = base64.encodebytes(t)  # 将返回的字节数据进行base64编码
        t = t.decode('utf-8')  # 将字节型数据转换成python中的字符串类型
        try:
            t = t.split()[0] + t.split()[1]  # 去除换行符
            print(t)
            return t
        except Exception as e:
            print(t)
            return t

    def ctr_base64_jiemi(self, text, keys, nonces):
        """CTR base64解密函数"""
        key = self.add_to_16(keys)
        text = base64.b64decode(text)  # 转换为base64格式，为bytes
        mode = AES.MODE_CTR
        nonces = nonces.encode('utf-8')  # 转换为bytes数据类型
        cryptor = AES.new(key, mode, nonce=nonces)
        try:
            plain_text = cryptor.decrypt(text)  # 解密
            print(plain_text)
            plain_text = unpad(plain_text, AES.block_size, style='pkcs7').decode()
            print(plain_text)  # 去掉字符串中右边的
            return plain_text
        except Exception as e:
            print('请检查解密数据或者密钥是否正确！')
            return '请检查解密数据或者密钥是否正确！'

    def ctr_hex_jiami(self, text, keys, nonces):
        """CTR hex加密函数"""
        key = self.add_to_16(keys)
        mode = AES.MODE_CTR
        nonces = nonces.encode('utf-8')  # 转换为bytes数据类型
        # text = self.add_to_16(text) # 不指定填充方式，默认为zeropadding填充
        pad_pkcs7 = pad(text.encode(), AES.block_size, style='pkcs7')  # 指定pkcs7填充，和pkcs5输出结果一样
        cryptos = AES.new(key, mode, nonce=nonces)
        t = cryptos.encrypt(pad_pkcs7)  # 加密明文，text必须为字节bytes
        t = bytes.decode(b2a_hex(t))
        try:
            t = t.split()[0] + t.split()[1]  # 去除换行符
            print(t)
            return t
        except Exception as e:
            print(t)
            return t

    def ctr_hex_jiemi(self, text, keys, nonces):
        """CTR hex解密函数"""
        key = self.add_to_16(keys)
        text = self.add_to_16(text)
        mode = AES.MODE_CTR
        nonces = nonces.encode('utf-8')  # 转换为bytes数据类型
        cryptor = AES.new(key, mode, nonce=nonces)
        try:
            plain_text = cryptor.decrypt(a2b_hex(text))  # 解密
            plain_text = unpad(plain_text, AES.block_size, style='pkcs7').decode()
            return plain_text
        except Exception as e:
            print('请检查解密数据或者密钥是否正确！')
            return '请检查解密数据或者密钥是否正确！'


class ECB_AES_JIEMI():
    """base64和HEX解密方法"""

    def jiemi_base64(self, keys, text):
        """解密：编码为base64输出"""
        print('加密数据=', text)
        text = base64.b64decode(text)  # 转换为base64格式，为bytes
        keys = keys.encode('utf-8')  # 将密钥进行编码，转换为bytes
        mode = AES.MODE_ECB  # 定义ecb模式
        cryptor = AES.new(keys, mode)  # 创建实例
        plain_text = cryptor.decrypt(text)  # 解密
        # print(bytes.decode(plain_text).rstrip('\r')) #去除结果中\r，进行decode编码，不然中文显示为unicode
        return bytes.decode(plain_text).rstrip('\r')

    def jiemi_hex(self, keys, text):
        """解密：编码为hex输出"""
        text = text.encode('utf-8')  # 进行utf-8编码，转为bytes
        keys = keys.encode('utf-8')  # 将密钥进行编码，转换为bytes
        mode = AES.MODE_ECB  # 定义ecb模式
        cryptor = AES.new(keys, mode)  # 创建实例
        plain_text = cryptor.decrypt(a2b_hex(text))  # 解密
        print(bytes.decode(plain_text).rstrip('\r'))  # 去除结果中\r，进行decode编码，不然中文显示为unicode
        return bytes.decode(plain_text).rstrip('\r')


# ECB_AES_JIEMI().jiemi_base64('785F0DAE8A7C4F59BFBAEBF7CDAACD2A','rlfStGTM3bv8gv1hmWAk3HFw/x9Yrbohh+w37XZAJmkr/4MdaF4r3AJVfOK+p7ZI+RLjByVVCCw3b5nwkrtzbIEpDRoSGlQxgOLeHLBVn+Yd+geLmMdWfRl/GfjPXFKkFP9TQF5GU65bbAfH3/rMvNoalLGxCQn+1tytoL4czrIKhcNiBPN1ymqKn3rpb3rxNTKbttTpCstqJ3YiK0+RIsNffsIslurOg3bxHFCMKLbVS/+3OFKDR62MwncP+k/E')
# ECB_AES_JIEMI().jiemi_hex('qdwphltib5kyfd3n','92c527b3fd5b6418ce2e2b22b68ec0b3464243ba84d68fa4d87ba5afee8f0d42ba8b3d9ac62bbe14fc801151b2e528aa70f3dade9a44b1ded267236602c104ebc39368397cd6ce7eee0658de153492f8df1ac38f09d5b034b170771176ecb54e')
# ECBandCBC_AES_jiami_AS_jiemi().ecb_hex_jiami('123','1234567812345678')
# ECBandCBC_AES_jiami_AS_jiemi().ecb_hex_jiemi('11072dd79ab1d526bd1266ec3ab1a0f7','1234567812345678')

# ECBandCBC_AES_jiami_AS_jiemi().ctr_base64_jiami('{"level":"green","cardID":"511*************979","name":"罗兵","type":"渝康码","covid_test":{}}','qdwphltib5kyfd3n','1234')
# ECBandCBC_AES_jiami_AS_jiemi().ctr_hex_jiami('{"parking_no": "浙A12345", "io_count": 100}','B0623EE1498FC9EB7E1600245D745313','RF_50_00000001')
ECBandCBC_AES_jiami_AS_jiemi().ctr_base64_jiemi(ECBandCBC_AES_jiami_AS_jiemi().ctr_base64_jiami('{"parking_no":"浙A12345","io_count":100}', 'B0623EE1498FC9EB7E1600245D745313', 'RF_50_00000001'), 'B0623EE1498FC9EB7E1600245D745313', 'RF_50_00000001')
# ECBandCBC_AES_jiami_AS_jiemi().cbc_hex_jiemi('6ad5bdf962b75728a134e3ed40a1e1fc9c0faf3fe35334d057289a30a0fac718b26c644cf74f79ad28965f252a33deed7d8f5c50e863351cf04ae1b3d61b9eee20a9ed9e579c1aea6927f9445f185aeb631836a7b77d12e95ffdff977e1dc6b75c4934d2b64c37990a0110e5c0f76632','qdwphltib5kyfd3n','1234567812345678')
# ECBandCBC_AES_jiami_AS_jiemi().cbc_base64_jiami('{"level":"green","cardID":"511*************979","name":"罗兵","type":"渝康码","covid_test":{}}','qdwphltib5kyfd3n','1234567812345678')
# ECBandCBC_AES_jiami_AS_jiemi().cbc_base64_jiemi('atW9+WK3VyihNOPtQKHh/JwPrz/jUzTQVyiaMKD6xxiybGRM9095rSiWXyUqM97tfY9cUOhjNRzwSuGz1hue7iCp7Z5XnBrqaSf5RF8YWutjGDant30S6V/9/5d+Hca3XEk00rZMN5kKARDlwPdmMg==','qdwphltib5kyfd3n','1234567812345678')
