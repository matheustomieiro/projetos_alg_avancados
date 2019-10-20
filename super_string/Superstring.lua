--[[
  Funcao que encontra a sopreposicao de duas strings
  args: String a, String b
  return: Integer Max(Maximo indice de sobreposicao), String c(String que contem a concatenacao das substrings) 
]]--
function encontraIndiceSobreposicao(a, b)
  local max = math.mininteger
  local n = math.min(string.len(a), string.len(b))
  local c = ""
  
  --Rodando para n vezes e comparando o final da string a com o inicio da string b
  for i=2, (n+1) do
    print(string.sub(a,-(i-1)))
    if (string.sub(a,-(i-1)) == string.sub(b,i)) then
      print("Entrou")
      if max < i then
        max = i
        c = a .. string.sub(b, i)
      end
    end
  end
  
  --Rodando para n vezes e comparando o final da string b com o inicio da string a
  for i=2, (n+1) do
    if (string.sub(a,i) == string.sub(b,-(i-1))) then
      print("Entrou")
      if max < i then
        max = i
        c = b .. string.sub(a,i)
      end
    end
  end
  return max, c
end


--[[
  Funcao que encontra uma superstring minima
  args: Lista de Strings na qual se deseja operar
  return: String que guarda a superstring minima
]]--
function encontraSuperStringMinima(lista)
  local lista_tam = #lista
  while lista_tam ~= 1 do
    max = math.mininteger
    local p = -1; local q = -1
    local final_str = ""
    print("LISTA MT LOKA: " .. lista[1])
    for i=1, (lista_tam) do
      for j = (i+1), (lista_tam) do
        local c
        max_len, c = encontraIndiceSobreposicao(lista[i],lista[j])
        print(max)
        if max < max_len then
          max = max_len
          final_str = c
          p = i
          q = j
        end
        
      end
      
    end
  
    lista_tam = lista_tam - 1
  
    if max == math.mininteger then
      lista[1] = lista[1] .. lista[lista_tam]
    else
      lista[p] = final_str
      lista[q] = lista[lista_tam]
    end
    
  end
  
  return lista[1]
  
end

--[[
  Funcao main, que inicia o programa
]]--
function main(args)
LISTA = {"CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC"}
print(encontraSuperStringMinima(LISTA))
end

main()