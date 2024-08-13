def sanar(fila, col, vidaInicial, vidaActual, d, mapa):
    maximaSanacion = 0
    for i in range(len(fila)):
        if es_posible_llegar(mapa,(fila[0],col[0]),(fila[i],col[i])):
            sanacion = min(10, vidaInicial[i] - vidaActual[i])
            if sanacion > maximaSanacion:
                maximaSanacion = sanacion
    return maximaSanacion
  
def es_posible_llegar(mapa, inicio, destino):
    filas = len(mapa)
    columnas = len(mapa[0])
    movimientos = [(-1, 0), (1, 0), (0, -1), (0, 1)] # movimientos
    por_explorar = [inicio] # posiciones por visitar
    visitados = [] #posisiones visitadas
    
    while por_explorar:
        x, y = por_explorar.pop(0)  # primer lugar para explorar
        if (x, y) == destino:
            return True

        visitados.append((x, y))

        for dx, dy in movimientos: #preuvo todos los movimientos
            nx, ny = x + dx, y + dy
            
            # comprobar que el movimiento sea posible
            if 0 <= nx < filas and 0 <= ny < columnas and mapa[nx][ny] == '.' and (nx, ny) not in visitados:
                por_explorar.append((nx, ny))
    return False

fila = [2,3,0,2,0,3]
col = [2,3,5,0,4,1]
vidaInicial = [13,40,40,50,40,6]
vidaActual = [10,34,1,48,32,1]
d = 4
mapa = [
    "..XX..",
    "...XXX",
    "...X..",
    "......",

]

print(sanar(fila, col, vidaInicial, vidaActual, d, mapa))
