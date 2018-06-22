# Viola Jones Object Detection
DIP Final Project - Viola Jones Object Detection  

---
## Face Detector  
### Result
<center><img src="/Result/face_result_1.bmp" width="50%" height="50%"></center>  
<center><img src="/Result/face_result_2.bmp" width="50%" height="50%"></center>  

### Evaluation  
| 50% Overlap | TP | FN | FP | Precision | Recall | TIME/IMAGE | TIME/OBJECT |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| `GR+GB+HE` | 856 | 242 | 18378 | 0.04 | 0.78 | 0.688 sec | 0.404 sec |  
| `GR+GB+HE+SD` | 491 | 607 | 4057 | 0.11 | 0.45 | 0.374 sec | 0.219 sec |
| `GR+HE+SD` | 517 | 581 | 2519 | 0.17 | 0.47 | 0.395 sec | 0.232 sec |
| `GR+SD` | 531 | 567 | 2246 | 0.19 | 0.48 | 0.395 sec | 0.232 sec |
| `BGR` | **`859`** | **`239`** | 11025 | 0.07 | **`0.78`** | 0.590 sec | 0.347 sec |
| `BGR+GB` | 838 | 260 | 17901 | 0.04 | 0.76 | 0.640 sec | 0.376 sec |  
| `BGR+SD` | 532 | 566 | **`2245`** | **`0.19`** | 0.48 | 0.381 sec | 0.224 sec |  
| `BGR+GB+SD` | 497 | 601 | 3512 | 0.12 | 0.45 | **`0.363 sec`** | **`0.213 sec`** |  

---
## Human Detector  
### Result  
  <center><img src="/Result/human_result_1.bmp" width="50%" height="50%"></center>  
  <center><img src="/Result/human_result_2.bmp" width="50%" height="50%"></center>  
  <center><img src="/Result/human_result_3.bmp" width="50%" height="50%"></center>  

### Evaluation  
| 50% Overlap | TP | FN | FP | Precision | Recall | TIME/IMAGE | TIME/OBJECT |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| `GR+GB+HE` | 199 | 150 | 1038 | 0.1609 | 0.5702 | 1.078 sec | 0.158 sec |  
| `GR+HE` | 174 | 175 | **`698`** | **`0.1995`** | 0.4986 | 1.118 sec | 0.163 sec |
| `GR+GB` | 199 | 150 | 1057 | 0.1584 | 0.5702 | **`1.019 sec`** | **`0.149 sec`** |
| `GR` | 172 | 177 | 713 | 0.1944 | 0.4928 | 1.039 sec | 0.152 sec |
| `BGR` | 172 | 177 | 713 | 0.1944 | 0.4928 | 1.039 sec | 0.152 sec |
| `BGR+GB` | **`200`** | **`149`** | 1061 | 0.1586 | **`0.5731`** | 1.098 sec | 0.160 sec |

---
## Vehicle Detector  
### Front  
#### Result  
  <center><img src="/Result/vehicle_result_front.bmp" width="50%" height="50%"></center>  
  

#### Evaluation
  | Front | TP | FN | FP | Precision | Recall | TIME/IMAGE | TIME/OBJECT |
  |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
  | `BGR` | 184 | 129 | 1468 | 0.11 | 0.58 | 0.352 sec | 0.239 sec |
  | `GR+HE` | 184 | 129 | 1570 | 0.10 | 0.58 | 0.356 sec | 0.245 sec |
  | `BGR+GB` | 186 | 127 | **`1331`** | **`0.12`** | 0.59 | 0.392 sec | 0.239 sec |
  | `GR+HE+GB` | **`191`** | **`122`** | 1464 | 0.12 | **`0.61`** | **`0.329 sec`** | **`0.223 sec`** |  


### Rear  
#### Result  
  <center><img src="/Result/vehicle_result_rear.bmp" width="50%" height="50%"></center>  
  
#### Evaluation
  | Rear | TP | FN | FP | Precision | Recall | TIME/IMAGE | TIME/OBJECT |
  |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
  | `BGR` | 219 | 118 | **`1132`** | 0.16 | 0.64 | 0.513 sec | 0.225 sec |
  | `GR+HE` | 219 | 118 | 1204 | 0.15 | 0.64 | 0.350 sec | **`0.199 sec`** |
  | `GR+GB` | **`236`** | **`101`** | 1207 | **`0.16`** | **`0.70`** | 0.356 sec | 0.201 sec |
  | `BGR+GB` | 226 | 111 | 1263 | 0.15 | 0.67 | 0.356 sec | 0.201 sec |
  | `GR+HE+GB` | 229 | 108 | 1251 | 0.15 | 0.67 | **`0.228 sec`** | 0.214 sec |
### Side
#### Result
  <center><img src="/Result/vehicle_result_side_1.bmp" width="50%" height="50%"></center>  
  
### Evaluation
| Side | TP | FN | FP | Precision | Recall | TIME/IMAGE | TIME/OBJECT |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| `BGR` | **`103`** | **`64`** | **`1943`** | **`0.050`** | **`0.61`** | 0.158 sec | 0.137 sec |
| `GR+HE` | 99 | 68 | 2058 | 0.045 | 0.59 | **`0.144 sec`** | **`0.125 sec`** |
| `BGR+GB` | 101 | 66 | 2017 | 0.047 | 0.60 | 0.158 sec | 0.137 sec |
| `GR+HE+GB` | 102 | 65 | 2128 | 0.046 | 0.61 | 0.202 sec | 0.179 sec |
