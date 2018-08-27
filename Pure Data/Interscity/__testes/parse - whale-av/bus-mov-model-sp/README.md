# Bus movement model of the city of São Paulo

This dataset contains eight models, one for each day of a week and one for a holiday eve. 
Each folder has two files: *buses.xml* and *map.xml*.

__Reference dates__: 2017/10/22 to 2017/10/28 (a week) and 2017/04/13 (easter eve)

### Description of files and attributes

#### buses.xml:

* __id__: represents the identifier of each bus line of the city. The last digit equal to 0 represents the departure from a bus' starting point. The last digit equal to 1 represents the return route. This data was gathered from the [SPTrans database](http://www.sptrans.com.br/desenvolvedores/GTFS.aspx) through the *trips.txt* file.
* __interval__: a 24-position list (from 0 to 23), separated by commas. Each position is a time range, where the position 0 means the interval between 0h00 and 0h59, position 1 is the interval between 1h00 and 1h59, and so on until 23h00. These positions store the frequency (in seconds) in which a bus departs with respect to a time range. These values combine information plan from the SPTrans and from the SPTrans' [Olho Vivo monitoring system](http://www.olhovivo.sptrans.com.br/).
* __start_time__: actual time in which a bus line started in that day. This data was obtained from the Scipopulis database, which in turns was gathered from the OlhoVivo.
* __stops__: a list containing all bus stops of a bus line. This data was gathered from the SPTrans database through the *stop_times.txt* file.

#### map.xml:

This file is composed of two tags "node" and "link"

__node__

* __id__: identifies a bus stop.
* __x__: latitude (UTM) of a bus stop. Source: SPTrans
* __y__: longitude (UTM) of a bus stop. Source: SPTrans

__link__

* __id__: identifies a link between two bus stops. 
* __from__: identifies a first bus stop or terminal station of a bus line. Source: SPTrans.
* __to__: identifies the final bus stop. Source: SPTrans.
* __length__: distance (meters) between the first and final bus stops. Souce: Scipopulis.
* __avgspeed__: a 24-position list (from 0 to 23), separated by commas. Each position represent the average speed of a bus line through a day. The position 0 means the average speed in the interval between 0h00 and 0h59, position 1 is the interval between 1h00 and 1h59, and so on until 23h00. The average speed is measured in meters per second taking into account the route referenced by the *link_id* identifier. Source: Scipopulis.
* __Shapes__: represents markers between bus stops (in meters). Shapes are defined by two position attributes:
    * __shapes_x__: a list of latitudes of the points that outline the way between two bus stops.
    * __shapes_y__: a list of longitudes of the points that outline the way between two bus stops.

---

#### Portuguese
# Modelo de movimentação de ônibus da cidade de São Paulo

Os modelos estão disponibilizados em oito pastas, uma para cada dia da semana. Em cada pasta existem dois arquivos que compõe cada um dos cenários: *buses.xml* e *map.xml*. 
__Datas de referência__: 22/10/2017 à 28/10/2017 (sete dias da semana) e 13/04/2017 (véspera do feriado de páscoa)

### Descrição dos arquivos e atributos

#### buses.xml:

* __id__: Campo que corresponde aos identificadores únicos de cada linha de ônibus por rota da cidade de São Paulo. Quando o último dígito é 0, representa  a rota de ida da linha e quando é 1 representa 
a rota de volta. Essa informação foi extraída da [base de dados da SPTrans](http://www.sptrans.com.br/desenvolvedores/GTFS.aspx), através do arquivo trips.txt.
* __interval__: Lista de 24 posições (variando de 0 a 23) separadas por vírgula. Cada posição da lista corresponde a uma faixa de horário, onde a posição 0 representa o intervalo de 0h00 até 0h59,
a posição 1 representa o intervalo de 1h00 até 1h59, e assim por diante até às 23h00. Nela são armazenadas as frequências (em segundos) em que os ônibus de uma determinada linha são lançados às 
ruas, considerando a faixa horária. Os valores combinam informações do planejamento da SPTrans e do sistema de monitoramento Olho Vivo, também da SPTrans. 
* __start_time__: Campo que apresenta o horário real em que a linha começou a circular naquele dia. Os dados foram retirados do banco de dados fornecido pela Scipopulis, capturadas pelo Olho Vivo.
* __stops__: O campo apresenta uma lista com as paradas de ônibus referentes a linha especificada. Tais pontos foram retirados do arquivo *stop_times.txt*. Fonte: SPTrans.

#### map.xml:

Esse arquivo é composto por duas tags "node" e "link"

__node__

* __id__: Identificador de uma parada de ônibus.
* __x__: Corresponde à latitude em UTM de determinada parada de ônibus. Fonte: SPTrans
* __y__: Corresponde à longitude em UTM de determinada parada de ônibus. Fonte: SPTrans

__link__

* __id__: Identificador de um link que faz ligação de duas determinadas paradas de ônibus da cidade. 
* __from__: Identificador da parada de origem/terminal de saída/primeira parada do itinerário de viagem. Fonte: SPTrans.
* __to__: Identificador da parada de destino. Fonte: SPTrans.
* __length__: Campo representa a distância em metros entre as paradas de ônibus de origem e destino. Fonte: Scipopulis;
* __avgspeed__: Lista que representa as velocidades médias de uma linha de ônibus, ao longo do dia. A lista possui 24 posições, variando de 0 a 23, onde cada posição da lista representa a velocidade média correspondente a uma faixa de horário (por exemplo: a posição 0 representa a velocidade média correspondente ao intervalo de 0h00 às 0h59, a posição 1 representa a velocidade média correspondente ao intervalo de 1h00, e assim por diante até as 23h00), levando em conta a via referenciada pelo identificador *link_id*. A velocidade é calculada em metros por segundo. Fonte: Scipopulis.
* __Shapes__: são pontos de referências (localizações em metros) que estão contidos dentro do espaço que liga uma parada de ônibus a outra. Eles serão definidos por dois novos atributos (um referente às latitudes e o outro às longitudes que os localizam:
    * __shapes_x__: lista de latitudes dos pontos que traçam o caminho entre duas paradas de ônibus.
    * __shapes_y__: lista de longitude dos pontos que traçam o caminho entre duas paradas de ônibus.

---
