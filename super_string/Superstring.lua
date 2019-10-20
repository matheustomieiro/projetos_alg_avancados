--[[
  Funcao que encontra a sopreposicao de duas strings
  args: String a, String b
  return: Integer Max(Maximo indice de sobreposicao), String c(String que contem a concatenacao das substrings) 
]]--
function encontraIndiceSobreposicao(a, b)
  local max = math.mininteger --Atribuindo a max um valor tao pequeno quanto possivel
  local n = math.min(string.len(a), string.len(b)) --Encontrando o menor valor entre os tamanhos de a e b
  local c = "" --Declarando uma variavel c que guarda uma substring
  
  --Rodando para n vezes e comparando o final da string a com o inicio da string b
  for i=2, (n+1) do
    if ( (string.sub(a,-(i-1)) == string.sub(b,i)) and (string.sub(b,i) ~= nil) ) then --Procuramos uma substring igual a outra
      if max < i then -- Se o indice for maior que o max anterior
        max = i -- Atualizamos max
        c = a .. string.sub(b, i) -- String c recebe a concatenacao de a com substring 0 a i de b
      end
    end
  end
  
  --Rodando para n vezes e comparando o final da string b com o inicio da string a
  for i=2, (n+1) do
    if ( (string.sub(a,i) == string.sub(b,-(i-1))) and (string.sub(a,i) ~= nil) ) then --Procuramos uma substring igual a outra
      if max < i then -- Se o indice for maior que o max anterior
        max = i -- Atualizamos max
        c = b .. string.sub(a,i) -- String c recebe a concatenacao de b com substring 0 até i de a
      end
    end
  end
  return max, c --Retorno duplo de max e da string c
end


--[[
  Funcao que encontra uma superstring minima
  args: Lista de Strings na qual se deseja operar
  return: String que guarda a superstring minima
]]--
function encontraSuperStringMinima(lista)
  local lista_tam = #lista --Salvando tamanho inicial da lista
  
  --Repete ate que haja somente o proprio elemento superstring minima na lista
  while lista_tam ~= 1 do
    max = math.mininteger --Atribuindo a max um valor tao pequeno quanto possivel
    local x = -1; local y = -1
    local final_str = ""
    print("LISTA MT LOKA: " .. lista[1])
    
    --Repeticao percorrendo todas as permutacoes da lista de strings
    for i=1, (lista_tam) do
      for j = (i+1), (lista_tam) do
        local max_indice, c
        max_indice, c = encontraIndiceSobreposicao(lista[i],lista[j]) -- max_indice recebe o primeiro retorno e c o segundo
        print(max, c)
        if max < max_indice then -- Se max_indice for maior que o max atual
          max = max_indice --Atualiza max
          final_str = c
          x = i
          y = j
        end
      end
    end
  
    lista_tam = lista_tam - 1 --Diminuimos os termos a serem vistos pelo for acima
  
    if max == math.mininteger then --Se max nao foi atualizado ainda
      lista[1] = lista[1] .. lista[lista_tam] --A string resultado sera a concatenacao dela mesma com a penultima posicao
    else --Caso contrario
      lista[x] = final_str -- A string da lista no indice salvo em X recebera a string final
      lista[y] = lista[lista_tam] --A string da lista no indice salvo em Y recebera a penultima string da lista atual
    end
    
  end
  
  return lista[1] -- Retornamos o primeiro termo, que foi usado como auxiliar
  
end

--[[
  Funcao main, que inicia o programa
]]--
function main(args)
LISTA = {"CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC"}
print(encontraSuperStringMinima(LISTA))
end

main()