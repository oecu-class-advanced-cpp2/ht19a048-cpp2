卒業研究
from sys import argv
from typing import Text
import MeCab
import re


# 取り出したい品詞
select_conditions = ['動詞', '助詞', '名詞']
select_conditionsd = ['動詞']
select_conditionsz = ['助詞']
select_conditionsm = ['名詞']

# 分かち書きオブジェクト
tagger = MeCab.Tagger('')
tagger.parse('')


def wakati_text(text):#動詞、助詞、名詞のみを取り出す

    # 分けてノードごとにする
    node = tagger.parseToNode(text)
    terms = []

    while node:

        # 単語
        term = node.surface

        # 品詞
        pos = node.feature.split(',')[0]

        # もし品詞が条件と一致してたら出力
        if pos in select_conditions:
            terms.append(term)

        node = node.next

    text_result = ' '.join(terms)
    return text_result


def wakati_text2(text):
    
    # 分けてノードごとにする
    node = tagger.parseToNode(text)
    terms = []
    l=0
    m=0
    n=0
    while node:

        # 単語
        term = node.surface

        # 品詞
        pos = node.feature.split(',')[0]

        # もし品詞が条件と一致してたら
        if pos in select_conditionsd and l==0:#動詞
            l=1
            terms.append(term)

        if pos in select_conditionsz and l==1 and m==0 and n==0:#助詞
            m=1
            terms.append(term)

        if pos in select_conditionsm and l==1  and n==0:#名詞
            n=1
            terms.append(term)
        
        node = node.next
    text_result = ' '.join(terms)
    if n==1:#名詞があれば出力
        return text_result
    return ('')
    
    
def kansu(text):
    tex = text
    tex = wakati_text(tex)#動詞、助詞、名詞のみを取り出す
    tex = tex.split(' ')#品詞ごとにくぎり
    tex.reverse()#順番逆転
    tex = ''.join(s for s in tex)#文字列結合
    tex = wakati_text2(tex)#動詞、助詞、名詞を順番に並べる
    tex=tex.split(' ')#品詞ごとにくぎり
    tex.reverse()#順番逆転
    tex = ''.join(s for s in tex)#文字列結合
    #原形で表示
    node = m.parseToNode(tex)
    Word = []
    while node:
        Word.append(node.feature.split(",")[6])
        node = node.next
    
    tex= ''.join(s for s in Word)#文字列結合
    tex=(tex.replace('*',''))#置き換え
    print(tex)
    #テキストボックスに書込み
    f = open('youyaku.txt', 'a')
    f.write(tex)
    f.write(n)
    f.close()
    return 

#MeCabで品詞ごとに分ける
m = MeCab.Tagger ("-Ochasen")
#テキストボックスから取り出す
f = open('C:/Users/ht19a048/Desktop/python/merosu.txt' , 'r' ,encoding='UTF-8')
text = f.read()
#名詞のみにする
nouns = [line.split()[0] for line in m.parse(text).splitlines()
               if "名詞" in line.split()[-1]]
n =("\n")

#一番多い名詞を割り出す
import collections
c = collections.Counter(nouns)

print("主人公の名前を右から順に1～5の中から選んでください")
print("なければ1～5以外を入力したのち直接入力して下さい")
e=print(c.most_common(5))
e = ''.join(s for s in c)

put = int(input("番号を選択:"))
if put == 1:
    a = (c.most_common()[0][0])
    b = (c.most_common()[0][1])
elif put == 2:
    a = (c.most_common()[1][0])
    b = (c.most_common()[1][1])
elif put == 3:
    a = (c.most_common()[2][0])
    b = (c.most_common()[2][1])
elif put == 4:
    a = (c.most_common()[3][0])
    b = (c.most_common()[3][1])
elif put == 5:
    a = (c.most_common()[4][0])
    b = (c.most_common()[4][1])
else :
    a = input()

#テキストボックスの準備
f = open('youyaku.txt', 'w')
f.close()

print(a)

#「」の中を削除
text = re.sub('\「.+?\」',"",text)
#選ばれた単語と［。］の間の文章を抜き取る
text=(text.replace(a, '%##'))
text=(text.replace('。', '##%'))
text=re.findall('%##(.*?)##%', text)
text = '\n'.join(s for s in text)
text=(text.replace('%##','\n'))

#行ごとに分ける
tex = text.split('\n')
d=0
for name in tex:
    kansu(tex[d])
    d+=1


