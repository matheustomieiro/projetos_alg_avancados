--OBS P/ JOAO: Em Lua, o vetor comeca em 1, entao onde o i comeca em 2, eh, na realidade, a segunda letra da string... (C/C++ str[1] onde em Lua str[2])

c = ""

--Funcao que encontra a sopreposicao de duas strings
function findOverlappingPair(a, b)
  max = math.mininteger
  n = math.min(string.len(a), string.len(b))
  
  for i=2, (n+1) do
    if (string.sub(a,-i) == string.sub(b,i-1)) then
      if max < 2 then
        max = i
        c = a .. string.sub(b, i+1)
      end
    end
  end
  
  for i=2, (n+1) do
    if (string.sub(a,1,i) == string.sub(b,-(i+1))) then
      if max < i then
        max = i
        c = b .. string.sub(a,i)
      end
    end
  end
  return max
end


function findShortestSuperstring(list)
  list_len = #list
  while list_len ~= 1 do
    max = math.mininteger
    p = -1; q = -1
    
    for i=1, (list_len) do
      for j = (i+1), (list_len) do
        max_len = findOverlappingPair(list[i],list[j])
        if max < max_len then
          max = max_len
          final_str = c
          p = i
          q = j
        end
      end
      
    end
  
    list_len = list_len - 1
  
    if max == math.mininteger then
      list[1] = list[1] .. list[list_len]
    else
      list[p] = final_str
      list[q] = list[list_len]
    end
  end
  return list[1]
end

LIST = {"CATGC", "CTAAGT", "GCTA", "TTCA", "ATGCATC"}
print(findShortestSuperstring(LIST))