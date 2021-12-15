'''
{
    "module":"SS_BUS_REQUEST",
    "type":"ss_reset_factory",
    "body":{
        "source":"client",
        "reset_level":1
    }
}
'''

cmd_tmp = '''{
                "module":"SS_BUS_REQUEST",
                "type":"ss_reset_factory",
                "body":{
                    "source":"client",
                    "reset_level":%d
                }
            }'''

def c_factory(webc, level):
    cmd = cmd_tmp % level
    # print('c_factory %s' % cmd)
    if webc is None:
        print('webc none')
        return 404, None

    ret = 404
    if webc.login():
        ret, resp = webc.posts(cmd)
        return ret, resp
    return ret, None
    # print(resp)