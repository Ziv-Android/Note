import requests

headers = {
    'user-agent': "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36",
}
url = 'https://mpvideo.qpic.cn/0b2e7qaaiaaa5yalsljffjrfb7gdat6aabaa.f10002.mp4?dis_k=9ea48e759e067ec71589231dec546a8c&dis_t=1646707970&vid=wxv_2299286102576332802&format_id=10002&support_redirect=0&mmversion=false'
video_title = "dog.mp4"
print('srart download.....：', video_title)
result = requests.get(url, headers=headers)
with open(video_title, 'wb') as f:
    f.write(result.content)
    print('download finised ....\n')


